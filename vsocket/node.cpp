/*********************************************
VSL - Virtual Socket Layer
Martin K. Schröder (c) 2012-2013

Free software. Part of the GlobalNet project. 
**********************************************/

#include "local.h"

Node::Node(Network *net){
	m_pNetwork = net;
	this->_output = 0;
	this->_input = 0;
	this->type = NODE_NONE;
	this->m_iRefCount = 1;
	
	/* set up the memory-buffer BIOs */
	/*this->read_buf = BIO_new(BIO_s_mem());
	this->write_buf = BIO_new(BIO_s_mem());
	BIO_set_mem_eof_return(this->read_buf, -1);
	BIO_set_mem_eof_return(this->write_buf, -1);
	
	this->in_read = BIO_new(BIO_s_mem());
	this->in_write = BIO_new(BIO_s_mem());
	BIO_set_mem_eof_return(this->in_read, -1);
	BIO_set_mem_eof_return(this->in_write, -1);
	*/
	m_bProcessingMainLoop = false;
	this->state = CON_STATE_INITIALIZED;
}

Node::~Node(){
	LOG(3,"NODE: deleting "<<this<<": "<<url.url());
	this->close();
	
	this->state = CON_STATE_UNINITIALIZED;
	/*if(this->_output && this->_output != this){
		if(this->_output->_input == this)
			this->_output->_input = 0;
		if(this->_output->_output == this)
			this->_output->_output = 0;
		delete _output;
	}*/
	/*
	if(this->_input && this->_input != this){
		if(this->_input->_input == this)
			this->_input->_input = 0;
		if(this->_input->_output == this)
			this->_input->_output = 0;
		delete _input;
	}*/
	
	
}

void Node::close(){
	/*if(read_buf) BIO_free(this->read_buf);
	if(write_buf) BIO_free(this->write_buf);
	if(in_read) BIO_free(this->in_read);
	if(in_write) BIO_free(this->in_write);
	
	read_buf = write_buf = in_read = in_write = 0;
	*/
	this->_output = 0;
	this->_input = 0;
}

/** internal function for establishing internal connections to other peers
Establishes a UDT connection using listen_port as local end **/
Node * Node::accept(){
	ERROR("CON_accept not implemented!");
	return 0;
}

int Node::connect(const URL &url){
	ERROR("CON_connect not implemented!");
	return -1;
}

int Node::send(const char *data, size_t size, size_t minsize){
	ERROR("CON_send not implemented!");
	return -1;
}
int Node::recv(char *data, size_t size, size_t minsize){
	ERROR("CON_recv not implemented!");
	return -1;
}


int Node::sendCommand(NodeMessage msg, const char *data, size_t size, const string &tag){
	// the default behavior is to simply pass the command down the line
	if(this->_output)
		this->_output->sendCommand(msg, data, size, tag);
	return 1;
}

int Node::sendCommand(const Packet &pack){
	// the default behavior is to simply pass the command down the line
	if(this->_output)
		this->_output->sendCommand(pack);
	//this->sendCommand((NodeMessage)pack.cmd.code, pack.data, pack.cmd.size, pack.cmd.hash.hex());
	return 1;
}
/*
int Node::recvCommand(Packet *dst){
	// only used by Peer. 
	//ERROR("CON: call to recvCommand(): NOT IMPLEMENTED!"); 
	return 0;
}
*/
void Node::run(){
	if(_output)
		_output->run();
}
int Node::listen(const URL &url){
	ERROR("CON_listen not implemented!");
	return -1;
}
void Node::peg(Node *other){
	ERROR("CON_bridge not implemented!");
}

void Node::set_output(Node *other){
	if(this->_output) delete _output;
	this->_output = other;
	if(other)
		other->set_input(this);
}
void Node::set_input(Node *other){ 
	this->_input = other;
	//other->set_output(this);
}
Node* Node::get_output(){
	return this->_output;
}
Node* Node::get_input(){
	return this->_input;
}

void Node::set_option(const string &opt, const string &val){
	options[opt] = val;
}

bool Node::get_option(const string &opt, string &res){
	if(options.find(opt) != options.end()){
		res = options[opt];
		return true;
	}
	return false;
}

