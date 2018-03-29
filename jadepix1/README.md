# Simulation(Iron-55, using allpix-squared) and analysis(scripts written by python) for jadepix1 on CEPC

To run the programs successfully, you may follow the following steps.

## Setup

ROOT verion 6, Geant4 version 4.10.04, allpix-squared version 1.1.0

This have to be done when you log in every time: 

> cd $HOME/jadepix/jadepix1

> source setup.sh

To use master allpix2: 

> source setup.sh master 


## Submit jobs

> cd $HOME/jadepix/jadepix1

> ./submit.sh

## For developers 

### Build softwares needed in simulation (one for allpix-squared developers)

> cd $HOME/jadepix/jadepix1

> ./build.sh 

- Fork the code with your personal github ID. See [details](https://help.github.com/articles/fork-a-repo/)

> git clone git@github.com:yourname/jadepix.git .

- Make your change, commit and push 

> git commit -a -m "Added feature A, B, C"
> git push

- Make a pull request to cepc. See [details](https://help.github.com/articles/using-pull-requests/)

## Some styles to follow 
- Minimize the number of main c++ files 
- Keep functions length less than one screen
- Seperate hard-coded cuts into script file
- Use pull-request mode on git 
- Document well the high-level bash file for work flow 


