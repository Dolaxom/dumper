from logger import log_message
from datetime import datetime

def on_message_handler(bot):
    @bot.client.event
    async def on_message(message):
        if on_message_validator(message, bot):
            return

        data = on_message_response_builder(message)
        log_message(data, datetime.now())

def on_message_response_builder(message):
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
    return message.author == bot.client.user or not message.channel.guild
