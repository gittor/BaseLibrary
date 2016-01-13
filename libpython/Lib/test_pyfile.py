#encoding=utf-8
import traceback
def main():
	try:
		import os
		import re
		import sys
		import xml
		import time, datetime
		return time.ctime( time.time() )

		return "hello"
	except Exception, e:
		return traceback.format_exc()
