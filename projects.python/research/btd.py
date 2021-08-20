# discover blue tooth devices

import bluetooth as bt

devices = bt.discover_devices()

for d in devices:
    print(d)


