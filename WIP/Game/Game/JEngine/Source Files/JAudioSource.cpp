#include "../Header Files/JAudioSource.h"

JAudioSource::JAudioSource(std::string _pathToAudio)
{
	soundBuffer.loadFromFile(_pathToAudio);
	float length = soundBuffer.getDuration().asSeconds();

	if (length > 30.0f) {
		isMusic = true;
		music.openFromFile(_pathToAudio);
	}
	else {
		sound.setBuffer(soundBuffer);
	}
}

JAudioSource::~JAudioSource()
{
}

void JAudioSource::Play()
{
	if (isMusic) {
		music.play();
	}
	else {
		sound.play();
	}
}

void JAudioSource::Pause()
{
	if (isMusic) {
		music.pause();
	}
	else {
		sound.pause();
	}
}

void JAudioSource::Stop()
{	
	if (isMusic) {
		music.stop();
	}
	else {
		sound.stop();
	}
}
