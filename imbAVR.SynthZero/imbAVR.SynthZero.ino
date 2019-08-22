#include <usb_ch9.h>
#include <Usb.h>
#include <parsetools.h>
#include <MouseController.h>
#include <KeyboardController.h>
#include <hidusagestr.h>
#include <hidboot.h>
#include <hid.h>
#include <confdescparser.h>
#include <adk.h>
#include <address.h>
#include <Adafruit_Circuit_Playground.h>
#include <Adafruit_CircuitPlayground.h>
#include <WiFiUdp.h>
#include <WiFiServer.h>
#include <WiFiClient.h>
#include <WiFi.h>
#include <TFT.h>
#include <TembooYunShield.h>
#include <TembooSSL.h>
#include <TembooMQTTEdgeDevice.h>
#include <TembooMonitoring.h>
#include <TembooCoAPEdgeDevice.h>
#include <Temboo.h>
#include <Stepper.h>
#include <SpacebrewYun.h>
#include <Servo.h>
#include <SD.h>
#include <LineFollow.h>
#include <ArduinoRobotMotorBoard.h>
#include <RobotIRremoteTools.h>
#include <RobotIRremoteInt.h>
#include <RobotIRremote.h>
#include <Mouse.h>
#include <LiquidCrystal.h>
#include <Keyboard.h>
#include <GSM3VoiceCallService.h>
#include <GSM3SoftSerial.h>
#include <GSM3SMSService.h>
#include <GSM3ShieldV1VoiceProvider.h>
#include <GSM3ShieldV1SMSProvider.h>
#include <GSM3ShieldV1ServerProvider.h>
#include <GSM3ShieldV1ScanNetworks.h>
#include <GSM3ShieldV1PinManagement.h>
#include <GSM3ShieldV1MultiServerProvider.h>
#include <GSM3ShieldV1MultiClientProvider.h>
#include <GSM3ShieldV1ModemVerification.h>
#include <GSM3ShieldV1ModemCore.h>
#include <GSM3ShieldV1DirectModemProvider.h>
#include <GSM3ShieldV1DataNetworkProvider.h>
#include <GSM3ShieldV1ClientProvider.h>
#include <GSM3ShieldV1CellManagement.h>
#include <GSM3ShieldV1BaseProvider.h>
#include <GSM3ShieldV1BandManagement.h>
#include <GSM3ShieldV1AccessProvider.h>
#include <GSM3ShieldV1.h>
#include <GSM3MobileVoiceProvider.h>
#include <GSM3MobileSMSProvider.h>
#include <GSM3MobileServerService.h>
#include <GSM3MobileServerProvider.h>
#include <GSM3MobileNetworkRegistry.h>
#include <GSM3MobileNetworkProvider.h>
#include <GSM3MobileMockupProvider.h>
#include <GSM3MobileDataNetworkProvider.h>
#include <GSM3MobileClientService.h>
#include <GSM3MobileClientProvider.h>
#include <GSM3MobileCellManagement.h>
#include <GSM3MobileAccessProvider.h>
#include <GSM3IO.h>
#include <GSM3CircularBuffer.h>
#include <GSM.h>
#include <FirmataParser.h>
#include <FirmataMarshaller.h>
#include <FirmataDefines.h>
#include <FirmataConstants.h>
#include <Firmata.h>
#include <Boards.h>
#include <Ethernet.h>
#include <YunServer.h>
#include <YunClient.h>
#include <Process.h>
#include <Mailbox.h>
#include <HttpClient.h>
#include <FileIO.h>
#include <Console.h>
#include <BridgeUdp.h>
#include <BridgeSSLClient.h>
#include <BridgeServer.h>
#include <BridgeClient.h>
#include <Bridge.h>
#include <midi_Settings.h>
#include <midi_Namespace.h>
#include <midi_Message.h>
#include <midi_Defs.h>
#include <MIDI.hpp>
#include <SquawkSD.h>
#include <Squawk.h>
#include <SdInfo.h>
#include <SdCard.h>
#include <Multiplexer.h>
#include <FatStructs.h>
#include <Fat16util.h>
#include <Fat16mainpage.h>
#include <Fat16Config.h>
#include <Fat16.h>
#include <EEPROM_I2C.h>
#include <EasyTransfer2.h>
#include <Compass.h>
#include <Arduino_LCD.h>
#include <ArduinoRobot.h>
#include <WaveShaper.h>
#include <WavePacketSample.h>
#include <WavePacket.h>
#include <StateVariable.h>
#include <Stack.h>
#include <Smooth.h>
#include <SampleHuffman.h>
#include <Sample.h>
#include <RollingStat.h>
#include <RollingAverage.h>
#include <ReverbTank.h>
#include <RCpoll.h>
#include <primes.h>
#include <Portamento.h>
#include <Phasor.h>
#include <PDResonant.h>
#include <OverSample.h>
#include <Oscil.h>
#include <mult32x16.h>
#include <mult16x8.h>
#include <mult16x16.h>
#include <mozzi_utils.h>
#include <mozzi_rand.h>
#include <mozzi_midi.h>
#include <mozzi_fixmath.h>
#include <mozzi_config.h>
#include <mozzi_analog.h>
#include <MozziGuts.h>
#include <Metronome.h>
#include <meta.h>
#include <LowPassFilter.h>
#include <Line.h>
#include <IntMap.h>
#include <EventDelay.h>
#include <Ead.h>
#include <DCfilter.h>
#include <ControlDelay.h>
#include <cogl_sqrti.h>
#include <CircularBuffer.h>
#include <AutoRange.h>
#include <AutoMap.h>
#include <AudioDelayFeedback.h>
#include <AudioDelay.h>
#include <AudioConfigTeensy3_12bit.h>
#include <AudioConfigStandardPlus.h>
#include <AudioConfigStandard9bitPwm.h>
#include <AudioConfigHiSpeed14bitPwm.h>
#include <ADSR.h>
#include <MIDI.h>
#include "noteList.h"
#include "pitches.h"

MIDI_CREATE_DEFAULT_INSTANCE();

#ifdef ARDUINO_SAM_DUE // Due has no tone function (yet), overriden to prevent build errors.
#define tone(...)
#define noTone(...)
#endif

// This example shows how to make a simple synth out of an Arduino, using the
// tone() function. It also outputs a gate signal for controlling external
// analog synth components (like envelopes).

static const unsigned sGatePin = 13;
static const unsigned sAudioOutPin = 10;
static const unsigned sMaxNumNotes = 16;
MidiNoteList<sMaxNumNotes> midiNotes;

// -----------------------------------------------------------------------------

inline void handleGateChanged(bool inGateActive)
{
	digitalWrite(sGatePin, inGateActive ? HIGH : LOW);
}

inline void pulseGate()
{
	handleGateChanged(false);
	delay(1);
	handleGateChanged(true);
}

// -----------------------------------------------------------------------------

void handleNotesChanged(bool isFirstNote = false)
{
	if (midiNotes.empty())
	{
		handleGateChanged(false);
		noTone(sAudioOutPin); // Remove to keep oscillator running during envelope release.
	}
	else
	{
		// Possible playing modes:
		// Mono Low:  use midiNotes.getLow
		// Mono High: use midiNotes.getHigh
		// Mono Last: use midiNotes.getLast

		byte currentNote = 0;
		if (midiNotes.getLast(currentNote))
		{
			tone(sAudioOutPin, sNotePitches[currentNote]);

			if (isFirstNote)
			{
				handleGateChanged(true);
			}
			else
			{
				pulseGate(); // Retrigger envelopes. Remove for legato effect.
			}
		}
	}
}

// -----------------------------------------------------------------------------

void handleNoteOn(byte inChannel, byte inNote, byte inVelocity)
{
	const bool firstNote = midiNotes.empty();
	midiNotes.add(MidiNote(inNote, inVelocity));
	handleNotesChanged(firstNote);
}

void handleNoteOff(byte inChannel, byte inNote, byte inVelocity)
{
	midiNotes.remove(inNote);
	handleNotesChanged();
}

// -----------------------------------------------------------------------------

void setup()
{
	tone(sAudioOutPin, 110, 200);
	tone(sAudioOutPin, 220, 200);
	tone(sAudioOutPin, 440, 200);

	pinMode(sGatePin, OUTPUT);
	pinMode(sAudioOutPin, OUTPUT);
	MIDI.setHandleNoteOn(handleNoteOn);
	MIDI.setHandleNoteOff(handleNoteOff);
	MIDI.begin();
}

void loop()
{
	MIDI.read();
}
