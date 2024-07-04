# Versioning of the Project
Norvi_Agent_1 (CST-BT-E-L)

SemVer: "<major>.<minor>.<patch>"
[semver](https://semverdoc.org/)

### Given a version number MAJOR.MINOR.PATCH, increment the:

MAJOR version when you make incompatible API changes,
MINOR version when you add functionality in a backwards-compatible manner, and
PATCH version when you make backwards-compatible bug fixes.

Bugfix      14.16.1 -> 14.16.2 (patch)

Feature     14.16.2 -> 14.17.0 (minor, downward compatible)

Breaking    14.17.0 -> 15.0.0  (major)

### Präfix Recomendation:
"feat:" -> Feature-Change: 14.16.2 -> 14.17.0
"feat!:" -> Feature, not downward compatible
"fix:" -> Bug-Fix or Patch
"fix!:" -> Bug-Fix or Patch,not downward compatible
"chore" -> clean up example: Remove some comments
"docs:" -> example: Update README.md
"refactor:" example rewrite function or class xyz

### Release-Logic:Conventional Commits:

https://github.com/semantic-release/semantic-release

The commit-message include the changes with prefix

------------------------------------------
Development Stage 0 (major-release)

Feature <ArduinoJson.h> change to not deprecated library
Hosting webserver on ESP32
Retrive data from webpage and save on ESP32 Flash memory
Retrive data from ESP32 Flash memory and push to webpage
Read date and time information from DS3231 RTC
Set alarms on DS3231 RTC for Special dates and week day information
Turn output ON and OFF based on current date and time and schedule
Connect to MQTT broker over NB-IoT
Publish start up data
Publish current consumption variable on a set interval
Subscribe to topics for schedule updates
Publish schedule on MQTT requests
------------------------------------------
Development Stage 1 (major-release: 1.x.y)


------------------------------------------
Development Stage 2 (major-release: 2.x.y)


------------------------------------------
Development Stage 3 (major-release: 3.x.y)


------------------------------------------
Development Stage 4 (major-release: 4.x.y)


