def on_ready_handler(bot):
    @bot.client.event
    async def on_ready():
        print(f'Dumper logged in as {bot.client.user}')
