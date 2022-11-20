# Equipamento de Eletrocardiograma Domiciliar

## Descrição
O Equipamento de Eletrocardiograma Domiciliar tem o objetivo de facilitar e popularizar a prática deste exame, sem que alguém que que se locomover até uma unidade hospitalar. Outros equipamentos que realizam exames médicos de forma móvel, sem que se tenha que se locomover até um local de exames, já são amplamente utilizados e obtiveram sucesso comercial.

## Componentes
O circuito do projeto é composto por um NodeMcu e um módulo ECG(AD8232) que pode se conectar com 3 eletroodos através de um cabo de conexão. O circuito foi montado de acordo com a imagem abaixo 

![alt text](https://github.com/arthurgcorrea/Ecg/blob/7722439268c9c18847e11d441b4d22304f823f24/Modelo%20Circuito.png)

## Conectividade
Neste projeto o NodeMcu se conecta a um fluxo do Node-RED na internet através do protocolo MQTT. Ele faz isso através de duas bibliotecas, a PubSubClient e a ESP8266WiFi, e se conecta ao broker no endereço "broker.mqtt-dashboard.com".

#
#

# Home Electrocardiogram Equipment

## Description
The Home Electrocardiogram Equipment has the goal of facilitating and regularizing the execution of an electrocardiogram, without having to go to a hospital. With the frequent use of this equipment, it’s expected that it’s users will be able to quickly and efficiently recognize anomalies related to the heart’s rhythm.

## Components
The circuit is projected to work with a NodeMcu and an ECG module(AD8232) that connects with 3 electrodes. The circuit was build following the model below:

![alt text](https://github.com/arthurgcorrea/Ecg/blob/7722439268c9c18847e11d441b4d22304f823f24/Modelo%20Circuito.png)

## Connectivity
In this project the NodeMcu connects to an Node-RED flow on the internet, using the MQTT protocol. It does that using two libraries, PubSubClient and ESP8266WiFi, and itconnects to the broker on the "broker.mqtt-dashboard.com" address.
