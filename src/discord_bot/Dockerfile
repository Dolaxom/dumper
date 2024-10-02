FROM python:3.11-slim

WORKDIR /app

COPY . .

RUN python3 -m pip install discord.py
RUN python3 -m pip install python-dotenv

# Запускаем бота
CMD ["python", "dumper/main.py"]
