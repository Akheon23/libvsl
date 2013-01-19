/*********************************************
VSL - Virtual Socket Layer
Martin K. Schröder (c) 2012-2013

Free software. Part of the GlobalNet project. 
**********************************************/

#include "local.h"

/** internal function for establishing internal connections to other peers
Establishes a UDT connection using listen_port as local end **/
Node * Node::accept(){
	ERROR("CON_accept not implemented!");
	return 0;
}

int Node::connect(const char *hostname, uint16_t port){
	ERROR("CON_connect not implemented!");
	return -1;
}

int Node::send(const char *data, size_t size){
	ERROR("CON_send not implemented!");
	return -1;
}
int Node::recv(char *data, size_t size){
	ERROR("CON_recv not implemented!");
	return -1;
}


int Node::sendCommand(NodeMessage msg, const char *data, size_t size){
	// the default behavior is to simply pass the command down the line
	if(this->_output)
		this->_output->sendCommand(msg, data, size);
	return 1;
}

int Node::recvCommand(Packet *dst){
	// only used by Peer. 
	//ERROR("CON: call to recvCommand(): NOT IMPLEMENTED!"); 
	return 0;
}

void Node::run(){
	if(_output)
		_output->run();
}
int Node::listen(const char *host, uint16_t port){
	ERROR("CON_listen not implemented!");
	return -1;
}
void Node::peg(Node *other){
	ERROR("CON_bridge not implemented!");
}

void Node::close(){
	ERROR("CONNECTION: close() has to be implemented!");
}


Node *Node::createNode(const char *name){
	if(strcmp(name, "peer")== 0){
		return new VSLNode(0);
	}
	else if(strcmp(name, "tcp")==0){
		return new TCPNode();
	}
	else if(strcmp(name, "udt")==0){
		return new UDTNode();
	}
	else if(strcmp(name, "ssl")==0){
		return new SSLNode();
	}
	else{
		ERROR("Unknown socket type '"<<name<<"'");
	}
	return 0;
}

Node::Node(){
	this->_output = 0;
	this->_input = 0;
	this->type = NODE_NONE;
	
	/* set up the memory-buffer BIOs */
	this->read_buf = BIO_new(BIO_s_mem());
	this->write_buf = BIO_new(BIO_s_mem());
	BIO_set_mem_eof_return(this->read_buf, -1);
	BIO_set_mem_eof_return(this->write_buf, -1);
	
	this->in_read = BIO_new(BIO_s_mem());
	this->in_write = BIO_new(BIO_s_mem());
	BIO_set_mem_eof_return(this->in_read, -1);
	BIO_set_mem_eof_return(this->in_write, -1);
	
	this->state = CON_STATE_INITIALIZED;
}

Node::~Node(){
	LOG("NODE: deleting "<<this->host<<":"<<this->port);
	
	BIO_free(this->read_buf);
	BIO_free(this->write_buf);
	BIO_free(this->in_read);
	BIO_free(this->in_write);
	
	read_buf = write_buf = in_read = in_write = 0;
	
	if(this->_output){
		if(this->_output->_input == this)
			this->_output->_input = 0;
		if(this->_output->_output == this)
			this->_output->_output = 0;
		delete _output;
	}
	if(this->_input){
		if(this->_input->_input == this)
			this->_input->_input = 0;
		if(this->_input->_output == this)
			this->_input->_output = 0;
		delete _input;
	}
	
	this->_output = 0;
	this->_input = 0;
	
	this->state = CON_STATE_UNINITIALIZED;
}
