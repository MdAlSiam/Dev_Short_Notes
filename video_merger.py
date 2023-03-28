# ./env/Scripts/activate

import cv2

k = 0

frames = []

video_dir = "./Camera Roll/19_05_01.mp4"

vidcap = cv2.VideoCapture(video_dir)
while True:
    success, frame = vidcap.read()
    if not success: break
    frames.append(frame)
    k += 1
    print("Appended 1", k)

print()
print()

k = 0

video_dir = "./Camera Roll/19_05_02.mp4"

vidcap = cv2.VideoCapture(video_dir)
while True:
    success, frame = vidcap.read()
    if not success: break
    frames.append(frame)
    print("Appended 2", k)

w, h, c = frames[0].shape
fourcc = cv2.VideoWriter_fourcc('m','p','4','v')
output_video = cv2.VideoWriter(f"./Camera Roll/19_05_M.mp4", fourcc, 30, (h, w))

for index, subtitled_frame in enumerate(frames):
    output_video.write(subtitled_frame)
output_video.release()
