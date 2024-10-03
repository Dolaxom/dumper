"""
Message arrival event handler from discord client

Provides the main on_message_handler() function and its helpers.
"""
import aiohttp
import discord
from dotenv import dotenv_values

from discord_client import DiscordClient
from logger import log_with_timestamp
from datetime import datetime

config = dotenv_values()

def on_message_handler(bot: DiscordClient):
    """

    Incoming message handler from discord client. Logic: Validation -> Processing -> Logging

    Parameters:

    bot: A discord.py package client object

    """

    @bot.client.event
    async def on_message(message: discord.Message):
        if message_validator(message, bot):
            return

        data = message_request_builder(message)
        await send_message_to_daas(data)
        log_with_timestamp(data, datetime.now())

def message_request_builder(message: discord.Message):
    """

    Create a Json object with data about a message received from a Discord client
 
    Parameters:
 
    message: A discord.py package object that stores information about a message and its owners
 
    Returns:
 
    Json object {server{id, name}, chat{id, name}, author{id, name}, content}

    """

    data = {
        "server": {
            "id": message.channel.guild.id,
            "name": message.channel.guild.name
        },
        "chat": {
            "id": message.channel.id,
            "name": message.channel.name
        },
        "author": {
            "id": message.author.id,
            "name": message.author.name
        },
        "content": message.content
    }

    return data

def message_validator(message: discord.Message, bot: DiscordClient):
    # Ignore private messages and messages from yourself(bot)
    return message.author == bot.client.user or not message.channel.guild

async def send_message_to_daas(data: dict):
    url = str(config['DAAS_URL']) + '/api/v1/message'
    headers = {'Content-Type': 'application/json'}

    async with aiohttp.ClientSession(url) as session:
        async with session.post(url, json=data, headers=headers) as response:
            log_with_timestamp(response.status, datetime.now())
