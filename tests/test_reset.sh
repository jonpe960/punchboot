#!/bin/bash
source tests/common.sh
echo "Waiting.."
wait_for_qemu_start
# Send reset command
echo "Sending reset"
$PB dev --reset --transport socket
wait_for_qemu


