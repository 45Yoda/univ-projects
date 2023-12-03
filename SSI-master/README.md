# SSI
Self-Sovereign Identity

Basic implementation following the Public Key Model:

    1- User generates keypair
    2- Sends public key to Identity Authority and document to attest
    3- Identity Authority associates public key with document and signs it
    4- Entity asks for information relative to a document
    5- User sends attested document with specific information only
    6- Entity confirms and associates public key with a nickname. Receives only documents signed with the user's private key.
