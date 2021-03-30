# CSE471 Project 1
## By: Jake Bosio (MSU ID- bosiojoh)


### Wavetable Bass Synthesizer
### Group Members: Jake Bosio
### Components and SCORE Details

#### Wavetable synthesis instrument
Createed a wavetable synthesis instrument that uses samples of different bass sound. This component supports ADSR envelope generation and pitch. For ADSR envelope generation, the attack, decay, and release are specified on a note while the sustain period is determined by the time between the decay and release periods. The short demonstration audio can be found at [`cse471_project_1\wavetablebass_test.wav`](https://github.com/bosiojoh/cse471_project_1/blob/8f94e48c57270ebf692036d00779090efbda09bf/wavetablebass_test.wav) and the SCORE file for this audio can be found at [`cse471_project_1\wavetablebass_test.score`](https://github.com/bosiojoh/cse471_project_1/blob/8f94e48c57270ebf692036d00779090efbda09bf/wavetablebass_test.score)

##### SCORE Format
Example:
```
<instrument instrument="WaveBass">
		<note measure="1" beat="1" duration="0.5" sample="1.0" attack="0.04" release="0.03" decay="0.06" rate="1.3"/>
<instrument />
```
`<instrument>` attributes:
`instrument`- set to "WaveBass" to specify wavetable synthesis instrument

`<note>` attributes:
`measure`, `beat`, `duration`- function as they are set up in Step 5 base project
`sample`- specify which 1 of 5 wave sample should be played for the note
`atack`- Length in seconds of the attack period for envelope generation
`decay`- Length in seconds of the decay period for envelope generation
`release`- Length in seconds of the release period for envelope generation
`rate`- used to change the pitch of a note. Specify the rate at which a note should be played. Ex: `2.0` would double the rate.



