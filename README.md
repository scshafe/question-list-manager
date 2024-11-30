

dependencies for running on bbb:

- libgtk-3
- xinit

dependencies for building:

- libgtkmm-3.0-dev
- libgtk-3-dev
<!-- - libgweather-3-dev (for retrieving weather information) -->
- libjsoncpp-dev
- libcurlpp-dev




# Configuration

### Running xinit from ssh

If during development, you would like to start the gui via ssh or a serial connection, you will need to change the file `/etc/X11/Xwrapper.config`.with the following line:
```
allowed_users=anybody
```

### Llama AI API key from Groq

The application uses an AI model to generate example sentences for the words. In order to include this functionality, you will need to get an API key (free for several thousand queries per day) and include it in a file called `groq-llama-api-key`


### Setting timezone

You will need to set your local timezone:

```
# timedatectl set-timezone [your-timezone]
```

Timezones can be found by running:
```
$ timedatectl list-timezones
```
 
### Setting the weather API username/word

This part is only necessary if you would like to include live weather information (current temperature, daily high, daily low, and updated sunrise/sunset).

You will need a username and password with meteomatics (free accounts for non-business purposes are available) in order to pull live weather information. On the BBB, export both of these as environment variables from the commandline:

```
$ export BBB_WEATHER_USERNAME=username
$ export BBB_WEATHER_PASSWORD=password
```