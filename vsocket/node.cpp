/*********************************************
VSL - Virtual Socket Layer
Martin K. Schröder (c) 2012-2013

Free software. Part of the GlobalNet project. 
**********************************************/

#include "local.h"

Node::Node(weak_ptr<Network> net){
	m_pNetwork = net;
	this->type = NODE_NONE;
	
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
	//m_pTransportLayer.reset();
}

/** internal function for establishing internal connections to other peers
Establishes a UDT connection using listen_port as local end **/
unique_ptr<Node> Node::accept(){
	ERROR("CON_accept not implemented!");
	return unique_ptr<Node>();
}

int Node::connect(const URL &url){
	ERROR("CON_connect not implemented!");
	return -1;
}

/*
int Node::sendCommand(NodeMessage msg, const char *data, size_t size, const string &tag){
	// the default behavior is to simply pass the command down the line
	if(this->m_pTransportLayer)
		this->m_pTransportLayer->sendCommand(msg, data, size, tag);
	return 1;
}

int Node::sendCommand(const Packet &pack){
	// the default behavior is to simply pass the command down the line
	if(this->m_pTransportLayer)
		this->m_pTransportLayer->sendCommand(pack);
	//this->sendCommand((NodeMessage)pack.cmd.code, pack.data, pack.cmd.size, pack.cmd.hash.hex());
	return 1;
}
*/
/*
int Node::recvCommand(Packet *dst){
	// only used by Peer. 
	//ERROR("CON: call to recvCommand(): NOT IMPLEMENTED!"); 
	return 0;
}
*/
void Node::run(){
	//m_pTransportLayer->run();
}
int Node::listen(const URL &url){
	ERROR("CON_listen not implemented!");
	return -1;
}
void Node::peg(Node *other){
	ERROR("CON_bridge not implemented!");
}
/*
void Node::output(shared_ptr<Node> other){
	m_pTransportLayer.reset();
	this->m_pTransportLayer = other;
	if(other)
		other->input(shared_ptr<Node>(this));
}
void Node::input(shared_ptr<Node> other){ 
	//this->m_pInput = other;
	//other->setOutput(this);
}
shared_ptr<Node> Node::output(){
	return this->m_pTransportLayer.lock();
}
shared_ptr<Node> Node::input(){
	//return this->m_pInput;
	return shared_ptr<Node>();
}
*/
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

