# CSE471 Project 1
## By: Jake Bosio (MSU ID- bosiojoh)


### Wavetable Bass Synthesizer
### Group Members: Jake Bosio
## Components and SCORE Details

#### Wavetable synthesis instrument
Createed a wavetable synthesis instrument that uses samples of different bass sounds. This component supports ADSR envelope generation and pitch. For ADSR envelope generation, the attack, decay, and release are specified on a note while the sustain period is determined by the time between the decay and release periods. The short demonstration audio can be found at [`cse471_project_1\wavetablebass_test.wav`](https://github.com/bosiojoh/cse471_project_1/blob/8f94e48c57270ebf692036d00779090efbda09bf/wavetablebass_test.wav) and the SCORE file for this audio can be found at [`cse471_project_1\wavetablebass_test.score`](https://github.com/bosiojoh/cse471_project_1/blob/8f94e48c57270ebf692036d00779090efbda09bf/wavetablebass_test.score)

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
`rate`- used to change the pitch of a note. Specify the rate at which a note should be played. Ex: `2.0` would double the rate and double the pitch.

#### Noise Gate Effect
Create a noise gate effect that blocks signals that register below a specified threshold. This threshold can be set on the effect in the SCORE file. The short demonstration audio can be found at [`cse471_project_1\noisegate_test.wav`](https://github.com/bosiojoh/cse471_project_1/blob/2eb2dd1d817f90bcf34074c8690c7e7e1e5930e6/noisegate_test.wav) and the SCORE file for this audio can be found at [`cse471_project_1\noisegate_test.score`](https://github.com/bosiojoh/cse471_project_1/blob/2eb2dd1d817f90bcf34074c8690c7e7e1e5930e6/noisegate_test.score)

##### SCORE Format
Example:
```
<instrument instrument="NoiseGate">
<note measure="2" threshold="0.25" />
</instrument>
```
`<instrument>` attributes:

`instrument`- set to "NoiseGate" to specify noise gate effect. This is passed like an instrument.

`<note>` attributes:

`measure`- set the measure the effect should be used on
`threshold`- set the threshould value for the effect. Example: If set to `0.30`, the noise gate will close when the frame is below a value of `0.30`

---

# Long Musical Audio
The longer demonstration audio can be found at [`cse471_project_1\long_audio.wav`](https://github.com/bosiojoh/cse471_project_1/blob/2eb2dd1d817f90bcf34074c8690c7e7e1e5930e6/long_audio.wav) and the SCORE file for this audio can be found at [`cse471_project_1\long_audio.score`](https://github.com/bosiojoh/cse471_project_1/blob/2eb2dd1d817f90bcf34074c8690c7e7e1e5930e6/long_audio.score). This makes use of all system components (Wavetable sythesizer and Noise Gate effect) and all of their capabilites (multiple samples, envelope generation, pitch, and noise gate effect).



