# audio-generator
For part 6 in sampling with PortAudio, I have attained the Wrapper, class, and implementation from https://github.com/orazdow/PortAudio-Wrapper. I give credits to 'orazdow.' This is for a sample run and will soon be a reference instead of full copied implementation (the class might stay but we will see).

Log:

7/3/2021 - Figured out how to adjust the user input data of the portaudio object. Check 'start' function.

7/12/2021 - The Portaudio and the Window must be separate to work for callback function for Portaudio. Next TODO: implement a way to adjust the tone of the sound based on the information of the mixer.