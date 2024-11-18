

dependencies for running on bbb:

- libgtk-3
- xinit

dependencies for building:

- libgtkmm-3.0-dev
- libgtk-3-dev




# Configuration

### Running xinit from ssh

If during development, you would like to start the gui via ssh or a serial connection, you will need to change the file `/etc/X11/Xwrapper.config`.with the following line:
```
allowed_users=anybody
```
