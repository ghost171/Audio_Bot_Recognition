# Audio_Bot_Recognition
This project representing Telegram Bot that reсognizes pronanciation of digits in audio.
## How to use the program?
You can execute audio_digits_recognition.py with command:
    
    python3 audio_digits_recognition_bot.py
Then you have to  send an audio message concerned word with digit.
If you want to change dataset or reset it you have to use the command:

    python3 audio_digits_dataset_bot.py
  
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
    def get_segment_energy(data, start, end):
    def get_segments_energy(data, segment_duration):
    def get_vad_mask(data, threshold):
    def sec2samples(seconds, sample_rate):
    class Segment:
    def print_segments(segments, single_duration, units_name):
    def mask_compress(data):    
## Accuracy of dataset
To check accuracy of dataset you can execute ml.py and run all the cells.
Under the cell with mean function you can see an answer.
## Audio recognition 
### audio_digits_recognition_bot.py
#### What does this program?
This program executes telegram-bot that receives an audio and recognize a digit in it with dataset basis.
It makes with predict() function help.
#### functions
The main function of this program is predict(), other only duplicate already written programs or response to functions of receiving and responsing messages.
So, let's сconsider predict():

    def predict(wav_path_after_vad):
        filename = "model.pkl"#it's model genrated in ml.py
        with open(filename, 'rb') as f:
            model_pickled = f.read()    
        model = pickle.loads(model_pickled)
        sample_rate, audio = read(wav_path_after_vad)
        max_duration_sec = 0.6

        max_duration = int(max_duration_sec * sample_rate + 1e-6)
        if len(audio) < max_duration:
            audio = np.pad(audio, (0, max_duration - len(audio)), constant_values = 0)

        assert len(audio) <= max_duration, "very long file"

        feature = librosa.feature.melspectrogram(audio.astype(float), sample_rate, n_mels = 80, fmax = 4000)
        print(feature.shape)
        features_flatten = feature.reshape(-1)
        print(features_flatten.shape)
        answer = model.predict([features_flatten])[0]
        return answer
