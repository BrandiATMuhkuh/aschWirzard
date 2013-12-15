/*
 * Copyright (c) 2012, 2013 Aldebaran Robotics. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the COPYING file.
 */
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iomanip>
#include <locale>
#include <sstream>
#include <string>
#include <iostream>
#include <unistd.h>
#include <stdlib.h>     //for using the function sleep
#include <time.h>

/*--		NAO INCLUDE			--*/
#include <alcore/alerror.h>
#include <alcommon/alproxy.h>
#include <alproxies/altexttospeechproxy.h>
#include <alproxies/albehaviormanagerproxy.h>
#include <alproxies/alaudioplayerproxy.h>
#include "xml/pugixml.hpp"



AL::ALBehaviorManagerProxy* nao1=NULL;
AL::ALBehaviorManagerProxy* nao2=NULL;
AL::ALBehaviorManagerProxy* nao3=NULL;
AL::ALBehaviorManagerProxy* nao4=NULL;
AL::ALAudioPlayerProxy* nao1Audio=NULL;
AL::ALAudioPlayerProxy* nao2Audio=NULL;
AL::ALAudioPlayerProxy* nao3Audio=NULL;
AL::ALAudioPlayerProxy* nao4Audio=NULL;
char* n1Ip = "10.0.1.9";//Aristotle
int n1port = 9559;
char* n2Ip = "Schopenhauer";
int n2port = 9559;
char* n3Ip = "Kant";
int n3port = 9559;
char* n4Ip = "Confucius";
int n4port = 9559;
int startCount = 0;

/*--		PROTOTYPES		--*/
bool ConnectProxies(std::string pip, int pport, AL::ALBehaviorManagerProxy** manager, AL::ALAudioPlayerProxy** amanager); //Connect the proxy for NAO - stop the program if it is impossible
int times,timed;


int main(int argc, char** argv)
{
  std::cout << "Hello, world" << std::endl;


  //connect R1
  if(!ConnectProxies(n1Ip,n1port, &nao1, &nao1Audio)) {
      std::cerr << std::endl << "no connection" << std::endl << std::endl;
      //exit(5);
  }

  //connect R2
  if(!ConnectProxies(n2Ip,n2port, &nao2, &nao2Audio)) {
      std::cerr << std::endl << "no connection" << std::endl << std::endl;
      //exit(5);
  }

  //connect R3
  if(!ConnectProxies(n3Ip,n3port, &nao3, &nao3Audio)) {
      std::cerr << std::endl << "no connection" << std::endl << std::endl;
      //exit(5);
  }

  //connect R4
  if(!ConnectProxies(n4Ip,n4port, &nao4, &nao4Audio)) {
      std::cerr << std::endl << "no connection" << std::endl << std::endl;
      //exit(5);
  }

  nao1 = nao1;
  nao1Audio = nao1Audio;
  nao2 = nao1;
  nao2Audio = nao1Audio;
  nao3 = nao1;
  nao3Audio = nao1Audio;
  nao4 = nao1;
  nao4Audio = nao1Audio;


  /*
    read json array.
    */
    pugi::xml_document doc;

    char* fileName = "/home/jbr134/Documents/Development/aschWirzard/aschWizrd/note.xml";

    std::cout << "argc: " << argc << " argv:" << argv[1] << std::endl;

    if(argc > 1){
        fileName = argv[1];
    }

    pugi::xml_parse_result result = doc.load_file(fileName);
    //pugi::xml_parse_result result = doc.load("<node attr='money'><child>text</child></node>");
    std::cout << "Load result: " << result.description() << ", mesh name: " << doc.child("Profile").attribute("attr").value() << std::endl;



    pugi::xml_node tools = doc.child("Tools");
    nao1->runBehavior("aschStartPosition");
    nao2->runBehavior("aschStartPosition");
    nao3->runBehavior("aschStartPosition");
    nao4->runBehavior("aschStartPosition");
    //nao4->runBehavior("aschSayHello");
    //nao4->runBehavior("aschAudios");

    times=time(NULL);
    for (pugi::xml_node_iterator it = tools.begin(); it != tools.end(); ++it){
        std::cout << "Tool: "<< it->attribute("count").value() << " " << it->attribute("type").value() <<std::ends;


        std::cout << " time " << (time(NULL)-times) <<std::ends;


        if(0 == strcmp(it->attribute("type").value(),"changeSlide")){

            std::cout << " changeSlide "<<std::ends;


            char buffer [256];
            sprintf (buffer, "curl -X PUT -H \"Content-Type: application/json\" -d '{\"pageNr\":%s}' http://localhost:2403/remote/ad886c6cf15138fb", it->attribute("slideCount").value());
            std::cout << "" << std::ends;
            system(buffer);
            //std::cin.get();

        }else if(0 == strcmp(it->attribute("type").value(),"robotSayAsch")){
            std::cout << " robotSay" <<std::ends;

            try {
                std::string playValue = "";
                playValue+="/home/nao/behaviors/aschAudios/";

                if(0 == strcmp(it->attribute("robotNr").value(),"0")){
                    playValue+="tim_";
                }else if(0 == strcmp(it->attribute("robotNr").value(),"1")){
                    playValue+="natalie_";
                }else if(0 == strcmp(it->attribute("robotNr").value(),"2")){
                    playValue+="julian";
                }else if(0 == strcmp(it->attribute("robotNr").value(),"3")){
                    playValue+="morgana_";
                }

                playValue+=it->attribute("sayWhat").value();
                playValue+=".wav";
                //char buffer [256];
                //sprintf (buffer,"/home/nao/behaviors/aschAudios/norm_%s.wav",it->attribute("sayWhat").value());

                //nao1Audio->playFile(playValue);
                if(0 == strcmp(it->attribute("robotNr").value(),"0")){
                    std::cout << "robot 0 talk" << std::endl;
                    nao1Audio->playFile(playValue);
                }else if(0 == strcmp(it->attribute("robotNr").value(),"1")){
                    std::cout << "robot 1 talk" << std::endl;
                    nao2Audio->playFile(playValue);
                }else if(0 == strcmp(it->attribute("robotNr").value(),"2")){
                    std::cout << "robot 2 talk" << std::endl;
                    nao3Audio->playFile(playValue);
                }else if(0 == strcmp(it->attribute("robotNr").value(),"3")){
                    std::cout << "robot 3 talk" << std::endl;
                    nao4Audio->playFile(playValue);
                }
                //nao1->runBehavior("sayOne");


            } catch (const AL::ALError& e) {
                std::cerr << std::endl << "Run behavior error" << std::endl << " Caught exception: " << e.what() << std::endl << std::endl;

            }

        }else if(0 == strcmp(it->attribute("type").value(),"robotSayWord")){
            std::cout << "not equl" << std::endl;

            try {
                std::string playValue = "";
                std::string playPastValue = "";
                playValue+="/home/nao/behaviors/aschAudios/";

                if(0 == strcmp(it->attribute("robotNr").value(),"0")){
                    playValue+="tim_";
                }else if(0 == strcmp(it->attribute("robotNr").value(),"1")){
                    playValue+="natalie_";
                }else if(0 == strcmp(it->attribute("robotNr").value(),"2")){
                    playValue+="julian";
                }else if(0 == strcmp(it->attribute("robotNr").value(),"3")){
                    playValue+="morgana_";
                }

                //hardEasy
                /*
                playValue+=it->attribute("hardEasy").value();
                playValue+="_";

                if(0 == strcmp(it->attribute("hardEasy").value(),"hard")){
                    playValue+=it->attribute("scheme").value();
                    playValue+="_";
                }*/

                playValue+=it->attribute("sayWhat").value();




                playPastValue=playValue;
                playValue+=".wav";
                playPastValue+="_p.wav";

                std::cout << "present" << playValue << " past " <<  playPastValue << std::endl;

                //char buffer [256];
                //sprintf (buffer,"/home/nao/behaviors/aschAudios/norm_%s.wav",it->attribute("sayWhat").value());


                if(0 == strcmp(it->attribute("robotNr").value(),"0")){
                    std::cout << "robot 0 talk" << std::endl;
                    nao1Audio->playFile(playValue);
                    //int mlSec = 300;
                    //usleep(mlSec * 1000);
                    //nao1Audio->playFile(playPastValue);
                }else if(0 == strcmp(it->attribute("robotNr").value(),"1")){
                    std::cout << "robot 1 talk" << std::endl;
                    nao2Audio->playFile(playValue);
                    //int mlSec = 300;
                    //usleep(mlSec * 1000);
                    //nao2Audio->playFile(playPastValue);
                }else if(0 == strcmp(it->attribute("robotNr").value(),"2")){
                    std::cout << "robot 2 talk" << std::endl;
                    nao3Audio->playFile(playValue);
                    //int mlSec = 300;
                    //usleep(mlSec * 1000);
                    //nao3Audio->playFile(playPastValue);
                }else if(0 == strcmp(it->attribute("robotNr").value(),"3")){
                    std::cout << "robot 3 talk" << std::endl;
                    nao4Audio->playFile(playValue);
                    //int mlSec = 300;
                    //usleep(mlSec * 1000);
                    //nao4Audio->playFile(playPastValue);
                }


                //nao1->runBehavior("sayOne");


            } catch (const AL::ALError& e) {
                std::cerr << std::endl << "Run behavior error" << std::endl << " Caught exception: " << e.what() << std::endl << std::endl;

            }


        }else if(0 == strcmp(it->attribute("type").value(),"robotSayHello")){
            std::cout << " robotSay" <<std::ends;

            try {
                std::string playValue = "";

                nao1->runBehavior("aschSayHello1");
                nao1->runBehavior("aschAudios");
                nao2->runBehavior("aschSayHello2");
                nao2->runBehavior("aschAudios");
                nao3->runBehavior("aschSayHello3");
                nao3->runBehavior("aschAudios");
                nao4->runBehavior("aschSayHello4");
                nao4->runBehavior("aschAudios");

                //nao1Audio->playFile(playValue);
                /*
                if(0 == strcmp(it->attribute("robotNr").value(),"0")){
                    nao1->runBehavior("aschSayHello1");
                    nao1->runBehavior("aschAudios");
                }else if(0 == strcmp(it->attribute("robotNr").value(),"1")){
                    nao2->runBehavior("aschSayHello2");
                    nao2->runBehavior("aschAudios");
                }else if(0 == strcmp(it->attribute("robotNr").value(),"2")){
                    nao3->runBehavior("aschSayHello3");
                    nao3->runBehavior("aschAudios");
                }else if(0 == strcmp(it->attribute("robotNr").value(),"3")){
                    nao4->runBehavior("aschSayHello4");
                    nao4->runBehavior("aschAudios");
                }*/


            } catch (const AL::ALError& e) {
                std::cerr << std::endl << "Run behavior error" << std::endl << " Caught exception: " << e.what() << std::endl << std::endl;

            }

        }


        //Waitings
        if(0 == strcmp(it->attribute("type").value(),"msWait")){
            std::string a = it->attribute("wait").value();
            int value = atoi(a.c_str());
            std::cout << " time to wait " << value << std::endl;
            usleep(value * 1000);
        }else if(0 == strcmp(it->attribute("type").value(),"input")){
            std::cout << " time for input " << std::endl;
            std::cin.get();
        }


        //std::cin.ignore();
        std::cout << std::endl;


        startCount++;
    }

    timed=time(NULL);
    times=timed-times;
    std::cout << "time from start to end" << times << std::endl;

   // pugi::xml_node child: tool.children();
    //std::cout << " bla: " << tools.children()[0].attribute("attr").value()<< " ending" <<std::endl;







  return 0;
}


/*--		CONNECTION TO NAO		--*/
bool ConnectProxies(std::string pip, int pport, AL::ALBehaviorManagerProxy** manager, AL::ALAudioPlayerProxy** amanager) {
    std::cout<<std::endl<< ">>>>>>>>>> Try to connect to NAO... <<<<<<<<<<" <<std::endl<<std::endl;
    //Connect the proxies
    try{
        *manager = new AL::ALBehaviorManagerProxy(pip,pport);
        *amanager = new AL::ALAudioPlayerProxy(pip,pport);
        //manager->runBehavior("sayOne");
        std::cout<<std::endl<< ">>>>>>>>>> Connection Success!! <<<<<<<<<<" <<std::endl;

        //Beh->runBehavior("really");
        return true;
    }
    //Return the error if there is one.
    catch (const AL::ALError& e){
        std::cerr << std::endl << ">>>>>>>>>> Connection Impossible!! <<<<<<<<<< " << std::endl << " Caught exception: " << e.what() << std::endl << std::endl;
        return false;
    }
}
