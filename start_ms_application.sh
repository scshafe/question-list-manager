#! /bin/bash

VOCAB_FILE=""

if [[ -z "$MS_VOCAB_DATABASE" ]]; then
  VOCAB_FILE="/home/debian/motion-sensor-configuration/vocabulary-words-test-argument.json"
  echo "Using default vocabulary database file: $VOCAB_FILE"
else
  VOCAB_FILE="$MS_VOCAB_DATABASE"
  echo "Using custom vocabulary database file path: $VOCAB_FILE"
fi



/home/debian/EMBEDDED-GUI --database-file $VOCAB_FILE
