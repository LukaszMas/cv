# How-To Extract single frame from the video using ffmpeg (cmd):

Ref guide at [stackexchange][1]

1. Using select filter:
    - `ffmpeg -i <input_video> -vf "select=eq(n\,<frame_num>)" -vframes 1 <output_name>`
        - Provide `input_video`, <frame_num>` and `<output_name>`

[1]: <https://superuser.com/questions/1009969/how-to-extract-a-frame-out-of-a-video-using-ffmpeg#:~:text=Use%20the%20FFmpeg%20executable%20with,jpg%20.> "stackexchange"
