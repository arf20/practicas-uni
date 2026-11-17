# Escenario B: llamada de manos libres

Llamada entre un teléfono (Audio Gateway, AG) y un kit de coche o auricular (Hands-Free, HF) por Bluetooth Clásico (BR/EDR). El control de la llamada viaja por el Hands-Free Profile (HFP) sobre RFCOMM y la voz por un enlace SCO/eSCO.

## 1. Conexión

- **Descubrimiento**: el HF se pone connectable y el móvil lo localiza por inquiry, o el HF pagina al móvil si ya se conocen.
- **Emparejamiento**: Secure Simple Pairing (Just Works en un auricular sin pantalla, comparación numérica en el coche). Se genera una link key que queda almacenada; solo se repite si se borra.
- **ACL + SDP**: se establece el enlace ACL y el HF consulta el registro SDP del AG (UUID 0x111F) para conocer el canal RFCOMM del HFP y sus características.
- **SLC (Service Level Connection)**: sobre RFCOMM se intercambian `AT+BRSF` (features), `AT+CIND=?` / `AT+CIND?` (indicadores), `AT+CMER` (notificación de eventos) y `AT+CHLD=?` (multillamada). Con esto el HF ya conoce el estado del teléfono.
- **Llamada**: al marcarse o responderse, el AG abre el enlace de voz SCO/eSCO. Al colgar se libera el audio, pero la SLC se mantiene para la siguiente llamada (reconexión rápida sin reemparejar).

## 2. Capas Bluetooth

- **Radio**: 2.4 GHz ISM, 79 canales de 1 MHz, modulación GFSK, FHSS a 1600 saltos/s, TDD y 1–100 mW (clase 2 típica, 10 m).
- **Baseband**: piconet con maestro y esclavos, slots de 625 µs; SCO con slots reservados para voz, ACL para control; FEC, ARQ y cifrado.
- **Link Manager (LMP)**: establece y controla el enlace, autentica, negocia el rol y crea los enlaces SCO/eSCO.
- **L2CAP**: multiplexa canales lógicos y segmenta; el control del HFP va en un canal RFCOMM.
- **RFCOMM**: emulación de puerto serie (TS 07.10) sobre L2CAP; transporta los comandos AT del HFP (y del SPP).
- **SDP**: base de datos de servicios; permite al HF descubrir el canal y las funciones del AG.
- **HFP**: capa de perfil/aplicación (comandos AT + audio). La voz **no** pasa por L2CAP/RFCOMM: va directamente en SCO/eSCO, y el códec (CVSD o mSBC) convierte entre PCM y el aire.

## 3. Dispositivos

- **AG**: smartphone (o módulo telefónico del coche). Implementa el stack clásico completo, el rol HFP AG, el servidor SDP y encamina la voz entre el módem celular/VoLTE y el enlace Bluetooth.
- **HF**: kit manos libres o auricular. Implementa HFP HF, micrófono y altavoz, cancelación de eco/ruido, botones de responder/colgar y el parser de comandos AT.
- Ambos necesitan **GAP, SDP, SPP y HFP**; el HF suele incluir HSP como respaldo y el coche añade PBAP/MAP (agenda, SMS) y A2DP/AVRCP (música).
- **Roles de enlace**: el AG suele ser maestro y el HF esclavo. Un AG puede atender varios HF, pero solo una llamada activa por HF.

## 4. Enlaces

- **ACL**: transporte de señalización, punto-multipunto, paquetes de 1, 3 o 5 slots, con ARQ. Siempre existe uno entre AG y HF.
- **SCO**: 64 kbit/s simétrico, slots reservados cada 2, 4 o 6, sin retransmisión y con FEC; paquetes HV1/HV2/HV3/DV; voz CVSD a 8 kHz. Es el enlace clásico del HFP.
- **eSCO**: variante con ventana de retransmisión y paquetes EV; HFP la usa desde la versión 1.5 y transporta mSBC (16 kHz) desde la 1.6.
- La voz se muestrea en PCM, se codifica (CVSD o mSBC) y se inserta en los slots SCO/eSCO; el maestro reserva el ancho de banda y el TDD alterna los sentidos.
- El enlace de audio solo existe durante la llamada; la link key cifra también la voz en el aire.

## 5. Perfiles

- **HFP (Hands-Free Profile)**: perfil principal, con roles AG y HF. Cubre responder/colgar, marcación por voz o repetición de la última llamada, llamada en espera y multillamada (`AT+CHLD`), indicadores (cobertura, batería, roaming), volumen (`AT+VGS`/`AT+VGM`), tono en banda y negociación de códec (`AT+BAC`/`AT+BCS`).
- **Versiones**: HFP 1.5 incorpora eSCO; HFP 1.6 añade voz de banda ancha (mSBC, 16 kHz); HFP 1.9 añade LC3-SWB (32 kHz).
- **HSP (Headset Profile)**: alternativa simple, solo responder/colgar/volumen y CVSD.
- **SPP**: proporciona el puerto serie (RFCOMM) sobre el que se montan los AT del HFP.
- **GAP**: descubrimiento, conexión, emparejamiento y roles.
- **Opcionales**: PBAP (agenda), MAP (SMS), A2DP/AVRCP (música).
- SDP anuncia los UUID 0x111E (HF) y 0x111F (AG); cada perfil es, como indica el Tema 6, el conjunto de partes de la pila que se implementan y se intercambian por SDP.

## 6. Posible implementación

- **HF de prototipo**: un ESP32 con ESP-IDF/Bluedroid (ejemplo `hfp_hf`): radio y stack clásico, SDP/RFCOMM/HFP, micrófono y altavoz por I2S y botones por GPIO. El firmware implementa la máquina de estados AT, responde a los eventos del AG y vuelca el PCM del códec al audio.
- **AG alternativa**: PC o Raspberry Pi con dongle USB Bluetooth y BlueZ + oFono (HFP AG); la voz se enruta con PipeWire/ALSA y el módem o una aplicación VoIP hace de red telefónica.
- **Flujo**: inicializar radio → registrar SDP y canal RFCOMM → emparejar por SSP → abrir RFCOMM y ejecutar la SLC → al responder, negociar códec y abrir eSCO → enviar/recibir PCM → `AT+CHUP` y cerrar el audio.
- **Verificación**: `btmon`/`btsnoop` con Wireshark para ver los AT y los paquetes SCO, y medida de latencia y eco para validar la calidad de voz.
