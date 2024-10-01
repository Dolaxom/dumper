from datetime import datetime
from dotenv import dotenv_values

from discord_client import DiscordClient
from logger import log_message
from on_message_handler import on_message_response_builder, on_message_validator

bot = DiscordClient()
config = dotenv_values()

@bot.client.event
async def on_ready():
    print(f'Dumper logged in as {bot.client.user}')

@bot.client.event
async def on_message(message):
    if on_message_validator(message, bot):
        return

    data = on_message_response_builder(message)
    log_message(data, datetime.now())


bot.client.run(config['DISCORD_TOKEN'])
