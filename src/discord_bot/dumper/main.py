"""
Main module of discord bot

Responsible for creating the bot, initializing the event handlers, and running the bot
"""

from discord_client import create_bot, run_bot
from events.on_message_handler import on_message_handler
from events.on_ready_handler import on_ready_handler

bot = create_bot()

on_ready_handler(bot)
on_message_handler(bot)

run_bot(bot)
