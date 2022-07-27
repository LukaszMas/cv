#How-To Install and use jetson-stats (cmd):

Ref guide at: [py-pi jetson-stats][1]

1. Installing jetson-stats:
    - `sudo -H pip3 install -U jetson-stats`
    - Reboot your board
    - Now you should be able to `jtop` to see all the jetson board stats:

2. Installing jetson-stats on virtual environment;
    - `virtualenv <venv_name>`
    - `source <venv_name>/bin/activate`
    - `pip3 install -U -jetson-stats`

[1]: <https://pypi.org/project/jetson-stats/> "pypi"
