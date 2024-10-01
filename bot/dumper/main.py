import datetime
import logging
import discord
from dotenv import dotenv_values
from datetime import datetime

config = dotenv_values()
logging.basicConfig(level=logging.INFO, filename="traces.log",filemode="w")

class DiscordClient:
    intents = discord.Intents.default()
    intents.message_content = True

    client = discord.Client(intents=intents)

bot = DiscordClient()

@bot.client.event
async def on_ready():
    print(f'Dumper logged in as {bot.client.user}')

@bot.client.event
async def on_message(message):
    if message.author == bot.client.user or not message.channel.guild:
        return

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
    logging.info(f"{datetime.now().strftime("%m/%d/%Y, %H:%M:%S")}: {data}")

bot.client.run(config['DISCORD_TOKEN'])
