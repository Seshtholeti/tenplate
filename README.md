import { ConnectClient, ListTagsForResourceCommand, UntagResourceCommand, TagResourceCommand } from "@aws-sdk/client-connect";
const client = new ConnectClient();
// Function to list tags for a resource
const listTagsForResource = async (resourceArn) => {
  const inputListTags = { resourceArn };
  const listTagsCommand = new ListTagsForResourceCommand(inputListTags);
  const listTagsResponse = await client.send(listTagsCommand);
  return listTagsResponse.tags;
};
// Function to untag a resource
const untagResource = async (resourceArn, tagKeys) => {
  const inputUntagResource = { resourceArn, tagKeys };
  const untagCommand = new UntagResourceCommand(inputUntagResource);
  const untagResponse = await client.send(untagCommand);
  return untagResponse;
};
// Function to tag a resource
const tagResource = async (resourceArn, tags) => {
  const inputTagResource = { resourceArn, tags };
  const tagCommand = new TagResourceCommand(inputTagResource);
  const tagResponse = await client.send(tagCommand);
  return tagResponse;
};
// Handler function
export const handler = async (event) => {
  try {
      console.log(event, event['arn']);
      if(event['intent']=='fetch'){
          // List tags for resource
      const tags = await listTagsForResource(event['arn']);
      console.log("Tags for resource:", tags);
      return tags
          
      }
      
      else if (event['intent'] == 'unTag'){
      const untagResponse = await untagResource(event['arn'], event["tagName"]);
      console.log("Resource untagged successfully:", untagResponse);
      return untagResponse
          
      }
       
      else{
          // Tag resource
        let keys={}
        keys[event['tagName']]=event['tagValue']
        console.log(keys)
      const tagResponse = await tagResource(event['arn'], keys);
      console.log("Resource tagged successfully:", tagResponse);
      return tagResponse 
      }
      
  } catch (error) {
      console.error("Error:", error);
      return {
          statusCode: 500,
          body: JSON.stringify({
              message: "An error occurred while processing the request.",
              error: error.message
          })
      };
  }
};
