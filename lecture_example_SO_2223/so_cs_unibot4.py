#!/usr/bin/env python3
# -*- coding: utf-8 -*-

"""Simple Bot show messages and count ballots

Renzo Davoli GPL3+

Based on the example in Telegram.ext:

This program is dedicated to the public domain under the CC0 license.
This Bot uses the Updater class to handle the bot.

First, a few handler functions are defined. Then, those functions are passed to
the Dispatcher and registered at their respective places.
Then, the bot is started and runs until we press Ctrl-C on the command line.

Usage:
Basic Echobot example, repeats messages.
Press Ctrl-C on the command line or send a signal to the process to stop the
bot.
"""

from telegram.ext import Updater, CommandHandler, MessageHandler, Filters
import logging
import sys
# import random
from datetime import datetime

# Enable logging
logging.basicConfig(format='%(asctime)s - %(name)s - %(levelname)s - %(message)s',
										level=logging.INFO)

logger = logging.getLogger(__name__)


# Define a few command handlers. These usually take the two arguments bot and
# update. Error handlers also receive the raised TelegramError object in error.

votes={}

def vote(update, context):
		global votes
		vote = update.message.text
		user = update.message.chat_id
		if vote[:5] == '/vote': vote = vote[5:]
		if vote[:1] == ' ': vote = vote[1:]
		vote = vote.lower()
		if user in votes:
			update.message.reply_text('vote changed to: '+ vote);
		else:
			update.message.reply_text('got your vote: '+ vote);
		votes[user] = vote

def count(update, context):
		global votes
		table = {}
		for v in votes:
			vote = votes[v]
			if vote in table:
				table[vote] += 1
			else:
				table[vote] = 1
		if table:
			print("Count results:")
		for v in sorted(table, key=table.get, reverse=True):
				print ('[{}]: {}'.format(v, table[v]))
		votes = {}

def start(update, context):
		update.message.reply_text('Welcome to unibot!')

def help(update, context):
		update.message.reply_text(
		"""
This is so_cs_unibot!
/vote file your votet
/count vote counting
	"""
	)

def echo(update, context):
		"""Echo the user message."""
		#print()
		print (datetime.now().strftime("%H:%M"), update.message.text)
		## update.message.reply_text(update.message.text)


def error(update, context):
		"""Log Errors caused by Updates."""
		logger.warning('Update caused error "%s"', context.error)


def main():
		if len(sys.argv) == 1:
			print("USAGE: {} keyfile".format(sys.argv[0]))
			return
		with open(sys.argv[1], 'r') as fd:
			token = fd.readline().strip()
		"""Start the bot."""
		# Create the EventHandler and pass it your bot's token.
		updater = Updater(token, use_context=True)

		# Get the dispatcher to register handlers
		dp = updater.dispatcher

		# on different commands - answer in Telegram
		dp.add_handler(CommandHandler("start", start))
		dp.add_handler(CommandHandler("help", help))
		dp.add_handler(CommandHandler("vote", vote))
		dp.add_handler(CommandHandler("count", count))

	 # on noncommand i.e message - echo the message on Telegram
		dp.add_handler(MessageHandler(Filters.text, echo))

		# log all errors
		dp.add_error_handler(error)

		# Start the Bot
		updater.start_polling()

		# Run the bot until you press Ctrl-C or the process receives SIGINT,
		# SIGTERM or SIGABRT. This should be used most of the time, since
		# start_polling() is non-blocking and will stop the bot gracefully.
		updater.idle()


if __name__ == '__main__':
		main()
