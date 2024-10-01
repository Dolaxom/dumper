import logging
import datetime


logging.basicConfig(level=logging.INFO, filename="traces.log",filemode="w")

def log_message(data, time):
    logging.info(f"{time.strftime("%m/%d/%Y, %H:%M:%S")}: {data}")