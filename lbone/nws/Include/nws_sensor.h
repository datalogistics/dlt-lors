/* $Id: nws_sensor.h,v 1.7 2000/01/28 20:37:16 swany Exp $ */

#ifndef SENSOR_H
#define SENSOR_H


#include "messages.h"  /* Message number ranges */


/*
** Messages recognized and/or generated by nws_sensor:
**
** ACTIVITY_START(name,control,skill,options) -- sent to the sensor to request
**   that it initiate a new activity.  The parameters are all null-terminated
**   strings.  #name# gives the registration name of the activity, #control#
**   the control in charge of the activity, #skill# the skill to be invoked,
**   and and #options# any parameterizations of the control or skill.  The
**   sensor replies with either a ACTIVITY_STARTED or a SENSOR_FAILED message
**   depending on success.
** ACTIVITY_STARTED(void) -- sent from the sensor as the successful reply to a
**   ACTIVITY_START message.
** ACTIVITY_STOP(name) -- sent to the sensor to request that it terminate the
**   activity named #name#, which is a nul-terminated string.  The sensor
**   replies with either a ACTIVITY_STOPPED or a SENSOR_FAILED message
**   depending on success or failure.
** ACTIVITY_STOPPED(void) -- sent from the sensor as the successful reply to a
**   ACTIVITY_STOP message.
** SENSOR_FAILED(void) -- sent from the sensor as the unsuccessful reply to a
**   ACTIVITY_START or ACTIVITY_STOP message.
*/

#define ACTIVITY_START   SENSOR_FIRST_MESSAGE
#define ACTIVITY_STARTED (ACTIVITY_START + 1)
#define ACTIVITY_STOP    (ACTIVITY_STARTED + 1)
#define ACTIVITY_STOPPED (ACTIVITY_STOP + 1)
#define SENSOR_FAILED    SENSOR_LAST_MESSAGE

#endif
