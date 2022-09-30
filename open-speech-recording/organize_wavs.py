# https://gist.githubusercontent.com/petewarden/64709e08226ba426b8708b60e497f813/raw/1a82ee500168752798bdbf32944d862fda7201ad/organize_wavs.py
# To convert from .ogg files to .wavs:
# find . -iname "*.ogg" -print0 | xargs -0 basename -s .ogg | xargs -I {} ffmpeg -i {}.ogg -ar 16000 ../converted_early_wavs/{}.wav
# Then run the extract_loudest xcode project to get one-second clips.

import glob
import os
import re
import shutil

data_index = {}

os.chdir('trimmed_wavs')
search_path = os.path.join('*.wav')
for wav_path in glob.glob(search_path):
    matches = re.search('([^/_]+)_([^/_]+)_([^/]+)\.wav', wav_path)
    if not matches:
        raise Exception('File name not in a recognized form:"%s"' % wav_path)
    word = matches.group(1).lower()
    speaker = matches.group(2).lower()
    instance = matches.group(3).lower()
    if not word in data_index:
      data_index[word] = {}
    if not speaker in data_index[word]:
      data_index[word][speaker] = {}
    if instance in data_index[word][speaker]:
        raise Exception('Audio instance already seen:"%s"' % wav_path)
    data_index[word][speaker][instance] = wav_path

output_dir = os.path.join('..', 'output_wavs')
try:
    os.mkdir(output_dir)
except:
    pass
for word in data_index:
  word_dir = os.path.join(output_dir, word)
  try:
      os.mkdir(word_dir)
  except:
      pass
  print('Created ' + word_dir)
  for speaker in data_index[word]:
    for instance in data_index[word][speaker]:
      wav_path = data_index[word][speaker][instance]
      output_path = os.path.join(word_dir, speaker + '_' + instance + '.wav')
      shutil.copyfile(wav_path, output_path)