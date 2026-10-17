class BBPRecipeBase extends Managed {
	
	string Title;
	string Result;
	autoptr BBPRecipePreviewItem PreviewItem;
	autoptr array<autoptr BBPRecipeItem> RequiredItems = new array<autoptr BBPRecipeItem>;
	autoptr array<autoptr BBPRecipeTool> RequiredTools = new array<autoptr BBPRecipeTool>;
	
	void BBPRecipeBase(string title, string result, BBPRecipePreviewItem previewItem, array<autoptr BBPRecipeItem> requiredItems, array<autoptr BBPRecipeTool> requiredTools){
		Title = title;
		Result = result;
		RequiredItems = requiredItems;
		RequiredTools = requiredTools;
		PreviewItem = previewItem;
	}
	
	
	array<autoptr BBPRecipeItem> GetRequiredItems(){
		return RequiredItems;
	}
	
	array<autoptr BBPRecipeTool> GetRequiredTools(){
		return RequiredTools;
	}
	
	string GetResult(){
		return Result;
	}

	string GetTitle(){
		return Title;
	}
	
	BBPRecipePreviewItem GetPreviewItem(){
		return PreviewItem;
	}
}

class BBPRecipeItem extends Managed {
	
	string ItemClassName;
	float Quantity;
	
	void BBPRecipeItem(string itemClassName,float quantity){
		ItemClassName = itemClassName;
		Quantity = quantity;
	
	}

}


class BBPRecipeTool extends Managed {
	
	string ToolClassName;
	void BBPRecipeTool(string className){
		ToolClassName = className;
	}
	

}

class BBPRecipePreviewItem extends Managed {
	
	string ItemClassName;
	autoptr TStringArray Parts;
	vector Orientation;
	void BBPRecipePreviewItem(string className, TStringArray parts, vector orientation = "0 0 0"){
		ItemClassName = className;
		Parts = parts;
		Orientation = orientation;
	}
	

}