#!/bin/bash

if [ -z "$1" ]; then
    echo "Usage: $0 <PID>"
    exit 1
fi

pid=$1

ps -p $pid -o f,s,uid,pid,ppid,c,pri,ni,addr,sz,wchan,tty,time,cmd

if [ $? -ne 0 ]; then
    echo "no process found for $pid"
fi