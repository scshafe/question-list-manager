#! /bin/bash



# check to see if the user has set an environment variable to override default database location
VOCAB_FILE=""

if [[ -z "$MS_VOCAB_DATABASE" ]]; then
  if [[ "$MS_VOCAB_DATABASE" != /* ]]; then
    echo "Error: $MS_VOCAB_DATABASE is relative. Must use absolute path for database override"
    return 1
  fi
  
  VOCAB_FILE="/home/debian/motion-sensor-configuration/vocabulary-words-test-argument.json"
  echo "Using default vocabulary database file: $VOCAB_FILE"
else
  VOCAB_FILE="$MS_VOCAB_DATABASE"
  echo "Using custom vocabulary database file path: $VOCAB_FILE"
fi

EXECUABLE_FILE="/home/debian/EMBEDDED-GUI"

if [[ -z "$MS_EXECUTABLE"]]; then
  EXECUABLE_FILE="$MS_EXECUTABLE"
fi

if [[ "$EXECUTABLE_FILE" != /* ]]; then
  echo "Error: $EXECUTABLE_FILE is relative. Must use absolute path for executable path"
  return 1
fi

$EXECUABLE_FILE --database-file $VOCAB_FILE
