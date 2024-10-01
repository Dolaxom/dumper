from discord_client import create_bot, run_bot
from on_message_handler import on_message_handler
from on_ready_handler import on_ready_handler

bot = create_bot()

on_ready_handler(bot)
on_message_handler(bot)

run_bot(bot)