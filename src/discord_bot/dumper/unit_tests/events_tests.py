import unittest
from unittest.mock import MagicMock

from ..events.on_message_handler import message_request_builder

class OnMessageHandler(unittest.TestCase):
    def test_on_message_response_builder(self):
        message = MagicMock()
        message.content = 'Some content'
        message.author.name = 'SomeUser#6666'
        message.author.id = 55
        message.channel.guild.name = 'Some Server'
        message.channel.guild.id = 12345
        message.channel.name = 'Some Channel'
        message.channel.id = 6789

        data = message_request_builder(message)

        expected_data = {
            "server": {
                "id": 12345,
                "name": 'Some Server'
            },
            "chat": {
                "id": 6789,
                "name": 'Some Channel'
            },
            "author": {
                "id": 55,
                "name": 'SomeUser#6666'
            },
            "content": 'Some content'
        }

        self.assertEqual(data, expected_data)


if __name__ == '__main__':
    unittest.main()
