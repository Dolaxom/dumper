import discord
from dotenv import dotenv_values

config = dotenv_values()

class DiscordClient:
    intents = discord.Intents.default()
    intents.message_content = True

    client = discord.Client(intents=intents)


def create_bot():
    return DiscordClient

def run_bot(bot):
    bot.client.run(config['DISCORD_TOKEN'])
