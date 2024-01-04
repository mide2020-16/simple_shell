#!/bin/bash

PID_MAX=$(cat /proc/sys/kernel/pid_max)

echo "Maximum process ID : $PID_MAX"
