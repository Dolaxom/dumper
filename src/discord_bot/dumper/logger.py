"""
Module for events and telemetry logging for discord bot

Provides out-of-the-box convenience features based on the “logging” library
"""

import logging

logging.basicConfig(level=logging.INFO, filename="traces.log",filemode="w")

def log_with_timestamp(data, time):
    logging.info(f"{time.strftime('%m/%d/%Y, %H:%M:%S')}: {data}")
