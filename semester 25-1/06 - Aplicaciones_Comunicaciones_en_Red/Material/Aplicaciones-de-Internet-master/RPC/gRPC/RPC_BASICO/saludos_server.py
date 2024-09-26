# Copyright 2015 gRPC authors.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
"""The Python implementation of the GRPC saludos.Saludar server."""

from concurrent import futures
import logging

import grpc
import saludos_pb2
import saludos_pb2_grpc

listaSaludos = ["Hello", "Salut", "Hallo", "Hola", "Merhaba"]


class Saludos(saludos_pb2_grpc.SaludosServicer):

    def DecirHola(self, request, context):
        return saludos_pb2.RespuestaSaludo(saludo='Hola, %s!' % request.nombre)

    def HolaEnVariosIdiomas(self, request, context):
        for idiom in listaSaludos:
            yield saludos_pb2.RespuestaSaludo(saludo=idiom + ', %s!' % request.nombre)

    def SaludaAMisAmigos(self, request_iterator, context):
        contador = 0
        saludos = "Hola"
        for request in request_iterator:
            contador += 1
            saludos += " ," + request.nombre
        return saludos_pb2.ResumenSaludos(contador_nombres=contador, saludo=saludos)

    def SaludaAMisAmigosEnVariosIdiomas(self, request_iterator, context):
        for request in request_iterator:
            for idiom in listaSaludos:
                yield saludos_pb2.RespuestaSaludo(saludo=idiom + ', %s!' % request.nombre)


def serve():
    server = grpc.server(futures.ThreadPoolExecutor(max_workers=10))
    saludos_pb2_grpc.add_SaludosServicer_to_server(Saludos(), server)
    server.add_insecure_port('[::]:50051')
    server.start()
    server.wait_for_termination()


if __name__ == '__main__':
    logging.basicConfig()
    serve()
