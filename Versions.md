# Versioning of the Project
Norvi_Agent_1 (CST-BT-E-L)

[Docs@ClickUp](https://doc.clickup.com/9015528544/d/h/8cnw330-1855/67cbbd3fecbb800)

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
### Development Stage 0 (major-release)
#### 0.0.1
- [x] Publish start up data
- [x] Connect to MQTT broker over NB-IoT
- [x]Send TestData @Thingsboard
- [ ]Subscribe to topics for schedule updates

- [x]Read the Sensordata from ACS712
- [ ]Implement EEPROM & Variables (global)
- [ ]Read date and time information from DS3231 RTC
- [ ]Set alarms on DS3231 RTC for Special dates and week day information
- [ ]Publish current consumption variable on a set interval
- [ ]Publish schedule on MQTT requests
- [ ] Serial Input ( Bidirectional from Serial to Serial1)
------------------------------------------
#### 0.1.0
- feat: Hosting webserver on ESP32
- feat: Retrive data from webpage and save on ESP32 Flash memory
- feat: Retrive data from ESP32 Flash memory and push to webpage
------------------------------------------
#### 0.2.0
- feat: Turn output ON and OFF based on current date and time and schedule
- feat: implement Serial2 AT Command iO
------------------------------------------
### Development Stage 1 (major-release: 1.x.y)
- Fix: <ArduinoJson.h> change to not deprecated library
- Free RTOS seperate Tasks to cores

------------------------------------------
### Development Stage 2 (major-release: 2.x.y)


------------------------------------------
### Development Stage 3 (major-release: 3.x.y)


------------------------------------------
### Development Stage 4 (major-release: 4.x.y)


