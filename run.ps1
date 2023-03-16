<#
you will need to install choco make

https://chocolatey.org/install

> Set-ExecutionPolicy Bypass -Scope Process -Force; [System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072; iex ((New-Object System.Net.WebClient).DownloadString('https://community.chocolatey.org/install.ps1'))
> choco install make

#>

cmake -B build\cmake -S . -G "Unix Makefiles"
make -C .\build\cmake

<#

execute the program by either clicking on the exe or typing: 

> .\build\bin\template.exe

obviously, replace the project name "template" with whatever youre using

#>