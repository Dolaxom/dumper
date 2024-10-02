"""
Event handler for bot launch

Provides the main on_ready_handler() function and its helpers.
"""

def on_ready_handler(bot):
    @bot.client.event
    async def on_ready():
        print(f'Dumper logged in as {bot.client.user}')
