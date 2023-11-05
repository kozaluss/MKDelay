/*
MKDelay v1.0
Author: Mateusz Kozicki "Kozaluss"
Date: 2023.11.05
*/

#include "MKDelay.h"

MKDelay::MKDelay(){
  MillisPrev = millis();
  Delta = 0;
  TimeOut = 1000; // domyslnie 1 sekunda
}

void MKDelay::SetTimeOut(long parTimeOut){
  TimeOut = parTimeOut;
}

void MKDelay::Reset(){
  MillisPrev = millis();
  Delta = 0;  
}

bool MKDelay::IsTimeOut(){
  if( GetDelta() < TimeOut ) return false;
  Reset();
  return true;
}

long MKDelay::GetDelta(){
  Delta += GetSubDelta();
  if( Delta < 0 ) Delta = 0;
  return Delta;
}

long MKDelay::GetSubDelta(){
  unsigned long MillisCurr = millis();
  long SubDelta = MillisCurr - MillisPrev;
  MillisPrev = MillisCurr;
  if( SubDelta > 100000 ) SubDelta = 0;
  if( SubDelta < 0 ) SubDelta = 0;
  return SubDelta;
}
