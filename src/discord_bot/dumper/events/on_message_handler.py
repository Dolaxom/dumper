"""
Message arrival event handler from discord client

Provides the main on_message_handler() function and its helpers.
"""

from logger import log_message_from_discord_client
from datetime import datetime

def on_message_handler(bot):
   """

    Incoming message handler from discord client. Logic: Validation -> Processing -> Logging

    Parameters:

    bot: A discord.py package client object 

   """

    @bot.client.event
    async def on_message(message):
        if on_message_validator(message, bot):
            return

        data = on_message_response_builder(message)
        log_message_from_discord_client(data, datetime.now())

def on_message_response_builder(message):
   """
 
    Create a Json object with data about a message received from a Discord client
 
    Parameters:
 
    message: A discord.py package object that stores information about a message and its owners
 
    Returns:
 
    Json object

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

def on_message_validator(message, bot):
    # Ignore private messages and messages from yourself(bot)
    return message.author == bot.client.user or not message.channel.guild
