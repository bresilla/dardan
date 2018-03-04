import hashlib, json, logging 
from datetime import datetime 



class Block:
	def __init__(self, index, timestamp, data, prevHash = ""):
		self.index = index
		self.timestamp = timestamp
		self.data = data
		self.prevHash = prevHash
		self.nonce = 0
		self.hash = self.hashBlock()
	
	def hashBlock(self):
		sha = hashlib.sha256()
		sha.update(str(self.index).encode("utf-8") + 
				str(self.timestamp).encode("utf-8") + 
				str(self.data).encode("utf-8") + 
				str(self.prevHash).encode("utf-8") +
				str(self.nonce).encode("utf-8"))  
		return sha.hexdigest()

	def mineBlock(self, difficulty):
		while self.hash[:difficulty] != "".join(map(str,[0 for i in range(difficulty)])):
			self.nonce += 1 
			self.hash = self.hashBlock()
		print("BLOCK MINED")


class Blockchain:
	def __init__(self):
		self.chain = [self.genesisBlock()]
		self.difficulty = 4

	def genesisBlock(self):
		return Block(0, datetime.now(), "GENESIS", "0")

	def latestBlock(self):
		return self.chain[-1]

	def newBlock(self, newBlock):
		newBlock.prevHash = self.latestBlock().hash
		newBlock.mineBlock(self.difficulty)

		print(newBlock.prevHash)
		print(newBlock.hash)

		self.chain.append(newBlock)

	def checkValidity(self, previousBlock, currentBlock):
		if previousBlock.hash != currentBlock.prevHash:
			return False
		else:
			return True
dardan = Blockchain()

print("MINING BLOCK ...")
dardan.newBlock(Block(1, datetime.now(), "55"))
print("MINING BLOCK ...")
dardan.newBlock(Block(1, datetime.now(), "5"))
print("MINING BLOCK ...")
dardan.newBlock(Block(1, datetime.now(), "15"))