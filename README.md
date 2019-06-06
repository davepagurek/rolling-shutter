# rolling-shutter
A script to offset rows of pixels in time to produce an extreme rolling shutter effect.

<img src="https://github.com/davepagurek/rolling-shutter/blob/master/img/Screen%20Shot%202019-06-06%20at%208.16.30%20AM.png?raw=true" />

Updating `rowsPerFrame` in `src/ofApp.cpp` changes the strength of the rolling shutter. With a 1080p video at 30fps, if you have one row per frame, you have 1080 / 30 = 36 seconds of difference between the first row of pixels and the last, resulting in an extreme amount of distortion.
