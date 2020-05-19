# Audio_Bot_Recognition
This project representing Telegram Bot that reсognizes pronanciation of digits in audio.

## Audio_bot
We have a telegram-bot that can receives audio, translate it to monocanal mode and put to wav directory.

## Dataset assembling
Dataset assemles from audio records with 5 digits in it. We need to despite this audio to 5 audios with digits and put this wav's to current directories.
To assemble the dataset we used to special programs for it:
adio_digits_dataset_bot.py
split_by_vad.py

### audio_digits_dataset.py
#### What does this program?
This program realizes audio bot receives digits for dataset.
#### functions 
This function just to save this audio file.

    def save_ogg(ogg_data, ogg_path):

This function convertes ogg to wav
    
    def convert_ogg_wav(ogg_path, dst_path):
Generate array with digits to say.
    
    def generate_task():
This is log to console.
    
    def log(text):
### split_by_vad.py
#### What does this program?
This program supposed to dividing audio record ro few record with human voice.
It used to dividing audio record with five digits in it to 5 records and put it to the appropriate in splitted/ directories.
#### functions


def print_with_timeline(data, single_duration, units_name, row_limit):
    for i in range(len(data)):
        if i % row_limit == 0:
            print(f"{single_duration * i:8.3f} {units_name} |  ", end='')
        print(f"{data[i]:.3f} ", end='')
        if (i + 1) % row_limit == 0 or i + 1 == len(data):
            print(f" | {single_duration * (i + 1):8.3f} {units_name}")


def get_segment_energy(data, start, end):
    energy = 0
    for i in range(start, end):
        energy += float(data[i]) * data[i] / (end - start)
    energy = np.sqrt(energy) / 32768
    return energy


def get_segments_energy(data, segment_duration):
    segments_energy  = []
    for segment_start in range(0, len(data), segment_duration):
        segment_stop = min(segment_start + segment_duration, len(data))
        energy = get_segment_energy(data, segment_start, segment_stop)
        segments_energy.append(energy)
    return segments_energy


def get_vad_mask(data, threshold):
    vad_mask = np.zeros_like(data)
    for i in range(0, len(data)):
        vad_mask[i] = data[i] > threshold
    return vad_mask


def sec2samples(seconds, sample_rate):
  return int(seconds * sample_rate)


class Segment:


def print_segments(segments, single_duration, units_name):


def mask_compress(data):
