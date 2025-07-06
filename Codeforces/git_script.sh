#!/bin/sh

git add $1;
git commit -m "Add $1";
git push origin main;
