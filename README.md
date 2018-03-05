# Laser Tag

Descripción

**laser-tag** is a free and open source software [licensed](#license) under the [GNU GPLv3.0 License](https://en.wikipedia.org/wiki/GNU_General_Public_License), unless otherwise specified in particular modules or libraries (see LICENSE and README.md).

## Table of Contents
- [Modules list](#modules-list)
- [Requirements](#requirements)
- [Getting Started](#getting-started)
- [Software details](#software-details)
- [Contributing](#contributing)
- [License](#license)

## Modules list
- [videostrip](https://github.com/MecatronicaUSB/uwimageproc/tree/master/modules/videostrip) Automatic frame extraction for 2D mosaic and 3D reconstruction 
- [bgdehaze](https://github.com/MecatronicaUSB/uwimageproc/tree/master/modules/bgdehaze) BG Haze removal for UW images
- [aclahe](https://github.com/MecatronicaUSB/uwimageproc/tree/master/modules/aclahe) Automatic Contrast-Limited AHE (CLAHE)
- [histretch](https://github.com/MecatronicaUSB/uwimageproc/tree/master/modules/histretch) Percentile based histogram stretch w/channel selection
- Automatic 2D mosaic generation > migrated to [mosaic](https://github.com/MecatronicaUSB/mosaic)
- 3D sparse and dense reconstruction > migrated to [uw-slam](https://github.com/MecatronicaUSB/uw-slam)

Each module contains information describing its usage, with (usually) some useful README file. Code documentation is expected to be provided in Doxygen-compatible format. The current release contains C/C++, Python and/or Matlab implementations.

## Requirements

The current release has been developed and tested in Ubuntu Windows 10 - 64 bits



## Getting Started

This repository provides an (increasing) collection of compatible, yet independent, underwater oriented modules for image and video. To start using this toolbox, proceed to the standard *clone* procedure:

```bash
cd <some_directory>
git clone https://github.com/Fedora-Eugenio/firmware.git
```

## Software Details

- Implementation done in Codewarrior + Processor Expert, Python and/or Processing.

## Contributing

Summary of contributing guidelines (based on those of OpenCV project):

* One pull request per issue;
* Choose the right base branch;
* Include tests and documentation;
* Use small datasets for testing purposes;
* Follow always the same coding style guide. If possible, apply code formating with any IDE.

## License

Copyright (c) 2017-2018 Fedora Di Polo - Eugenio Martínez
Released under the [GNU GPLv3.0 License](LICENSE). 
