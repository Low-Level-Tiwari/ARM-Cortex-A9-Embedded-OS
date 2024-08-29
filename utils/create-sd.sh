#!/bin/bash

qemu-img create $1 64M
qemu-nbd -c /dev/nbd0 $1

(echo o; 
echo n; echo p 
echo 1
echo ; echo
echo w; echo p) | fdisk /dev/nbd0
mkfs.ext2 -t ext2 /dev/nbd0p1

mkdir tmp || true
mount -o user /dev/nbd0p1 tmp/
cp $2 tmp/
umount /dev/nbd0p1
rmdir tmp || true
qemu-nbd -d /dev/nbd0
