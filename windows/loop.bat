for /l %%x in (1,1,219) do (
%~dp0\x64\Debug\testing.exe | curl -X POST --data-binary @- http://192.168.125.200:5000/dump
)